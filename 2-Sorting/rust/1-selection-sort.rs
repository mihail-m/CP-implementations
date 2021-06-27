// Selection sort

mod sort {
    /// Sort the given array via selection sort
    /// Complexity: O(array.len()^2)
    pub fn selection_sort(array: &mut Vec<i32>) {
        for i in 0..array.len() {
    
            let mut selected = i;
    
            for j in i..array.len() {
                if array[selected] > array[j] {
                    selected = j;
                }
            }
    
            array.swap(selected, i);
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_selection_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::selection_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
