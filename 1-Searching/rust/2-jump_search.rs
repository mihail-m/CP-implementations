// Jump Search

mod search {
    use std::cmp;

    /// Find if the provided value is contained in the 
    /// provided vector of values via jump search.
    ///
    // Complexity: O(sqrt(values.len()))
    ///
    /// The vector values is expected to be in sorted order.
    pub fn jump_search(values: &Vec<i32>, value: i32) -> bool {
        if values.len() == 0 {
            return false;
        }
    
        let jump: usize = (values.len() as f32).sqrt() as usize + 1;
        
        let mut index: usize = 0;
        
        while index < values.len() {
            if values[index] == value {
                return true;
            }
            
            if values[index] > value {
                break;
            }
            
            index = cmp::min(index + jump, values.len());
        }
        
        let mut offset: usize = 1;
        
        while offset < jump && offset <= index {
            if values[index - offset] == value {
                return true;
            }
        
            offset = offset + 1;
        }
        
        return false;
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_jump_search() {
        assert!(crate::search::jump_search(&vec![-2, 0, 2, 3, 7, 24], 3)); 
    }
    
    #[test]
    fn test_jump_search_negative() {
        assert!(!crate::search::jump_search(&vec![-2, 0, 2, 3, 7, 24], 4)); 
    }
}
