#include <iostream>
#include <string>

class ConfigurationSettings {
private:
    // Const data member
    const std::string m_configFileName;
    int m_maxConnections;
    
public:
    ConfigurationSettings(const std::string& fileName, int maxConnections)
        : m_configFileName(fileName), m_maxConnections(maxConnections) {
        std::cout << "Creating configuration with file: " << m_configFileName << std::endl;
    }
    
    // Getter for the const member
    const std::string& getConfigFileName() const {
        return m_configFileName;
    }
    
    int getMaxConnections() const {
        return m_maxConnections;
    }
    
    // Regular setter for non-const member
    void setMaxConnections(int maxConnections) {
        m_maxConnections = maxConnections;
    }
    
    // DANGEROUS: Using const_cast to modify a const member
    void forceChangeConfigFile(const std::string& newFileName) {
        std::cout << "WARNING: Using const_cast to modify a const member!" << std::endl;
        
        // Get a non-const reference to the const member using const_cast
        std::string& nonConstRef = const_cast<std::string&>(m_configFileName);
        
        // Modify the string through the non-const reference
        nonConstRef = newFileName;
        
        std::cout << "Changed config file to: " << m_configFileName << std::endl;
    }
    
    // Even more dangerous - modifying a const object
    static void modifyConstObject(const ConfigurationSettings& constSettings) {
        std::cout << "\nDANGER: Attempting to modify a const object!" << std::endl;
        
        // Cast away constness of the entire object
        ConfigurationSettings& nonConstSettings = 
            const_cast<ConfigurationSettings&>(constSettings);
        
        // Now we can call non-const methods on the cast object
        nonConstSettings.setMaxConnections(100);
        nonConstSettings.forceChangeConfigFile("hacked_config.ini");
        
        std::cout << "After modification (appears to work but may be undefined behavior):" << std::endl;
        std::cout << "File: " << constSettings.getConfigFileName() << std::endl;
        std::cout << "Max Connections: " << constSettings.getMaxConnections() << std::endl;
    }
};

int main() {
    // Case 1: Modifying a const member of a non-const object
    std::cout << "=== Case 1: Modifying a const member of a non-const object ===" << std::endl;
    ConfigurationSettings settings("default.cfg", 10);
    
    std::cout << "Before modification:" << std::endl;
    std::cout << "File: " << settings.getConfigFileName() << std::endl;
    std::cout << "Max Connections: " << settings.getMaxConnections() << std::endl;
    
    // Use const_cast to modify const member
    settings.forceChangeConfigFile("new_config.cfg");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "File: " << settings.getConfigFileName() << std::endl;
    std::cout << "Max Connections: " << settings.getMaxConnections() << std::endl;
    
    // Case 2: Attempting to modify a truly const object
    std::cout << "\n=== Case 2: Attempting to modify a truly const object ===" << std::endl;
    const ConfigurationSettings constSettings("readonly.cfg", 5);
    
    std::cout << "Before modification:" << std::endl;
    std::cout << "File: " << constSettings.getConfigFileName() << std::endl;
    std::cout << "Max Connections: " << constSettings.getMaxConnections() << std::endl;
    
    // This is where it gets dangerous - modifying a truly const object
    ConfigurationSettings::modifyConstObject(constSettings);
    
    // The program might crash here or exhibit other undefined behavior
    
    return 0;
}