// Counting sort

mod sort {
    use std::cmp;

    /// Sort the given array via counting sort
    ///
    /// Complexity: If the numbers in the array are in the range [a, b]
    /// then the complexity is O(b - a).
    pub fn counting_sort(array: &mut Vec<i32>) {
        let mut offset = i32::MAX;
        let mut max_element = i32::MIN;

        for num in array.iter() {
            max_element = cmp::max(max_element, *num);
            offset = cmp::min(max_element, *num);
        }
    
        if offset < 0 {
            offset = -offset;
        } else {
            offset = 0;
        }
        
        let mut count: Vec<i32> = vec![0; (max_element + offset + 1) as usize];
    
        for num in array.iter() {
            let index = (*num + offset) as usize;
            count[index] = count[index] + 1;
        }
    
        let mut index: usize = 0;
    
        for num in 0..count.len() {
            while count[num] > 0 {
                array[index] = (num as i32) - offset;
                count[num] = count[num] - 1;
                index = index + 1;
            }
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_counting_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::counting_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
