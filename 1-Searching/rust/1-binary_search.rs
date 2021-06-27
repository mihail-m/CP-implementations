// Binary Search

mod search {
    /// Find if the provided value is contained in the 
    /// provided vector of values via binary search.
    ///
    // Complexity: O(log2(values.len()))
    ///
    /// The vector values is expected to be in sorted order.
    pub fn binary_search(values: &Vec<i32>, value: i32) -> bool {
        if values.len() == 0 {
            return false;
        }
    
        let mut left: usize = 0;
        let mut right: usize = values.len() - 1;
        
        while left <= right {
            let mid: usize = (left + right) / 2;
            
            if values[mid] == value {
                return true;
            }
            
            if values[mid] < value {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_binary_search() {
        assert!(crate::search::binary_search(&vec![-2, 0, 2, 3, 7, 24], 3)); 
    }
    
    #[test]
    fn test_binary_search_negative() {
        assert!(!crate::search::binary_search(&vec![-2, 0, 2, 3, 7, 24], 4)); 
    }
}
