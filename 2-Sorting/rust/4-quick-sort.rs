// Quick sort

mod sort {
    /// Sort the given array via quick sort
    /// Complexity: O(array.len()*log2(array.len())) on average,
    /// but O(array.len()^2) worst case
    pub fn quick_sort(array: &mut Vec<i32>, left: i32, right: i32) {
        if left >= right {
            return;
        }
    
        let pivot: i32 = partition(array, left as usize, right as usize) as i32;
    
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
    
    fn partition(values: &mut Vec<i32>, left: usize, right: usize) -> usize { 
        let pivot: usize = left + rand::random::<usize>() % (right - left + 1);
    
        values.swap(right, pivot);
    
        let mut i: usize = left;
    
        for j in left..right {
            if values[j] <= values[right] {
                values.swap(i, j); 
                i = i + 1; 
            } 
        } 
        
        values.swap(i, right);
        
        return i; 
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_quick_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        let from: i32 = 0;
        let to: i32 = (test_array.len() - 1) as i32;
        crate::sort::quick_sort(&mut test_array, from, to);
    
        assert_eq!(expected_result, test_array);
    }
}
