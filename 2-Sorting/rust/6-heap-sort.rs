// Heap sort

mod sort {
    /// Sort the given array via heap sort
    /// Complexity: O(array.len()*log2(array.len()))
    pub fn heap_sort(array: &mut Vec<i32>) {
        for i in (0..array.len() / 2).rev() {
            hepify(array, array.len(), i);
        }
        
        for i in (0..array.len()).rev() {
            array.swap(i, 0);
            hepify(array, i, 0);
            
        }
    }
    
    fn hepify(array: &mut Vec<i32>, n: usize, node: usize) {
        let left = 2 * node + 1;
        let right = 2 * node + 2;
    
        let mut new_node = node;
    
        if left < n && array[left] > array[new_node] {
            new_node = left;
        }
    
        if right < n && array[right] > array[new_node] {
            new_node = right;
        }
    
        if new_node != node {
            array.swap(node, new_node);
            hepify(array, n, new_node);
        }
    }
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_heap_sort() {
        let mut test_array: Vec<i32> = vec![5, 1, 4, 7, 13, 2];
        let expected_result: Vec<i32> = vec![1, 2, 4, 5, 7, 13];
    
        crate::sort::heap_sort(&mut test_array);
    
        assert_eq!(expected_result, test_array);
    }
}
