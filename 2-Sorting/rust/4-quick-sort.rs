// Quick sort
// Worst case complexity: O(n^2)
// Average case complexity: O(n log n) 

use rand::Rng;

fn partition(array: &mut [i32], left: usize, right: usize) -> usize {

    let pivot = rand::thread_rng().gen_range(left, right + 1);

    array.swap(right, pivot);

    let mut pivot = left;

    for j in left..right {
        if array[j] <= array[right] {
            array.swap(pivot, j);
            pivot = pivot + 1;
        }
    }

    array.swap(pivot, right);

    return pivot;
}

fn quick_sort(array: &mut [i32], left: usize, right: usize) {
    if left >= right {
        return;
    }

    let pivot = partition(array, left, right);

    quick_sort(array, left, pivot - 1);
    quick_sort(array, pivot + 1, right);
}

fn test() {
    let mut test_array: [i32; 6] = [5, 1, 4, 7, 13, 2];
    let expected_result: [i32; 6] = [1, 2, 4, 5, 7, 13];

    quick_sort(&mut test_array, 0, 5);
    
    assert_eq!(expected_result, test_array);
}

fn main() {
    test();
}
