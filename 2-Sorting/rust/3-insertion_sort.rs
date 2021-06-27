// Selection sort

mod sort {
    /// Sort the given array via bubble sort
    /// Complexity: O(array.len()^2)
    pub fn insertion_sort(array: &mut Vec<i32>) {
        for i in 1..array.len() {
    
            let mut j = i;
    
            while j > 0 && array[j] < array[j - 1] {
                array.swap(j, j - 1);
                j = j - 1
            }
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_insertion_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::insertion_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
