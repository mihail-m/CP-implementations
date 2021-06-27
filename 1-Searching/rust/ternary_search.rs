// Ternary Search

mod search {
    /// Find if the provided value is contained in the 
    /// provided vector of values via ternary search.
    ///
    // Complexity: O(log3(values.len()))
    ///
    /// The vector values is expected to be in sorted order.
    pub fn ternary_search(values: &Vec<i32>, value: i32) -> bool {
        if values.len() == 0 {
            return false;
        }
    
        let mut left: usize = 0;
        let mut right: usize = values.len() - 1;
    
        while left <= right {
            let mid1: usize = left + (right - left) / 3;
            let mid2: usize = right - (right - left) / 3;
    
            if values[mid1] == value || values[mid2] == value {
                return true;
            }
    
            if value < values[mid1] { 
                right = mid1 - 1; 
            } else if value > values[mid2] { 
                left = mid2 + 1; 
            } else { 
                left = mid1 + 1;
                right = mid2 - 1; 
            }
        }
    
        return false;
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_ternary_search() {
        assert!(crate::search::ternary_search(&vec![-2, 0, 2, 3, 7, 24], 3)); 
    }
    
    #[test]
    fn test_ternary_search_negative() {
        assert!(!crate::search::ternary_search(&vec![-2, 0, 2, 3, 7, 24], 4)); 
    }
}
