// Quick select

mod search {
    use rand;

    /// Find the k-th smallest value contained in the 
    /// provided vector of values via quick select.
    ///
    // Complexity: values.len() on average and O(values.len()^2) worst case
    ///
    pub fn kth_smallest(values: &mut Vec<i32>, k: usize) -> i32 {
        let mut left: usize = 0;
        let mut right: usize = values.len() - 1;
    
        while left <= right {
            let pivot: usize = partition(values, left, right);
    
            if pivot == k - 1 {
                return values[pivot];
            }
    
            if pivot < k - 1 {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
    
        return i32::MIN;
    }
    
    fn partition(values: &mut Vec<i32>, left: usize, right: usize) -> usize  { 
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
    fn test_kth_smallest() {
        assert_eq!(crate::search::kth_smallest(&mut vec![7, 0, -2, 2, 3, 24], 3), 2); 
    }
    
    #[test]
    fn test_kth_smallest_negative() {
        assert_eq!(crate::search::kth_smallest(&mut vec![7, 0, -2, 2, 3, 24], 12), i32::MIN); 
    }
}
