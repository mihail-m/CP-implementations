// Selection sort

mod sort {
    /// Sort the given array via bubble sort
    /// Complexity: O(array.len()^2)
    pub fn bubble_sort(array: &mut Vec<i32>) {
        for i in 0..array.len() {
            for j in ((i + 1)..array.len()).rev() {
    
                if array[j] < array[j - 1] {
                    array.swap(j, j - 1);
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_bubble_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::bubble_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
