// Radix sort

mod sort {
    use std::cmp;

    /// Sort the given array via radix sort
    ///
    /// Complexity: If the number of digits of the largest number in the array 
    /// is D then the complexity is O(D * array.len()).
    pub fn radix_sort(array: &mut Vec<i32>) {
        let mut max_num = i32::MIN;
        
        for num in array.iter() {
            max_num = cmp::max(max_num, *num);
        }
    
        let mut pos = 1;
        
        while max_num / pos > 0 {
            counting_sort(array, pos);
            pos = pos * 10;
        }
    }

    fn counting_sort(array: &mut Vec<i32>, pos: i32) {
        let mut count: Vec<i32> = vec![0; 10];
    
        for num in array.iter() {
            let index = ((*num / pos) % 10) as usize;
            count[index] = count[index] + 1;
        }
        
        for i in 1..10 {
            count[i] = count[i] + count[i - 1 as usize];
        }
    
        let mut res: Vec<i32> = vec![0; array.len()];
    
        for i in (0..array.len()).rev() {
            let digit = ((array[i] / pos) % 10) as usize;
            res[(count[digit] - 1) as usize] = array[i];
            count[digit] = count[digit] - 1;
        }
        
        *array = res;
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_radix_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::radix_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
