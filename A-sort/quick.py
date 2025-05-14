def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        
        # Elements less than or equal to pivot
        less = [x for x in arr[1:] if x <= pivot]
        
        # Elements greater than pivot
        greater = [x for x in arr[1:] if x > pivot]
        
        # Recursively sort both sub-arrays and combine with pivot
        return quick_sort(less) + [pivot] + quick_sort(greater)

# Example usage with in-place version
def quick_sort_in_place(arr, low=0, high=None):
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Partition the array and get the pivot index
        pivot_index = partition(arr, low, high)
        
        # Recursively sort the sub-arrays
        quick_sort_in_place(arr, low, pivot_index - 1)
        quick_sort_in_place(arr, pivot_index + 1, high)
    
    return arr

def partition(arr, low, high):
    # Choose the rightmost element as pivot
    pivot = arr[high]
    
    # Index of smaller element
    i = low - 1
    
    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            # Increment index of smaller element
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    # Place pivot in its correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    
    # Return the pivot index
    return i + 1

# Example usage
if __name__ == "__main__":
    # Using the functional version
    test_array1 = [10, 7, 8, 9, 1, 5]
    sorted_array1 = quick_sort(test_array1)
    print(f"Original array: {test_array1}")
    print(f"Sorted array (functional): {sorted_array1}")
    
    # Using the in-place version
    test_array2 = [10, 7, 8, 9, 1, 5]
    sorted_array2 = quick_sort_in_place(test_array2.copy())
    print(f"Sorted array (in-place): {sorted_array2}")