// Merge sort

mod sort {
    /// Sort the given array via merge sort
    /// Complexity: O(array.len()*log2(array.len()))
    pub fn merge_sort(array: &mut Vec<i32>, left: i32, right: i32) {
        if left >= right {
            return;
        }
        
        let mid = (left + right) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        
        merge(array, left as usize, mid as usize, right as usize);
    }
    
    fn merge(array: &mut Vec<i32>, left: usize, mid: usize, right: usize) {
        let left_half = array[left..mid + 1].to_vec();
        let right_half = array[mid + 1..right + 1].to_vec();
    
        let mut pos: usize = left;
        let mut i: usize = 0;
        let mut j: usize = 0;
    
        while i < left_half.len() && j < right_half.len() {
            if left_half[i] <= right_half[j] {
                array[pos] = left_half[i];
                i = i + 1;
            } else {
                array[pos] = right_half[j];
                j = j + 1;
            }
            pos = pos + 1;
        }
        
        while i < left_half.len() {
            array[pos] = left_half[i];
            i = i + 1;
            pos = pos + 1;
        }
        
        while j < right_half.len() {
            array[pos] = right_half[j];
            j = j + 1;
            pos = pos + 1;
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_merge_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        let from: i32 = 0;
        let to: i32 = (test_array.len() - 1) as i32;
        crate::sort::merge_sort(&mut test_array, from, to);
    
        assert_eq!(expected_result, test_array);
    }
}
