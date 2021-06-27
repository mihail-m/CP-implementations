// Bubble sort
// Complexity: O(n^2)

fn bubble_sort(array: &mut [i32]) {
	for i in 0..array.len() {
		for j in ((i + 1)..array.len()).rev() {

			if array[j] < array[j - 1] {
				array.swap(j, j - 1);
			}
		}
	}
}

fn test() {
	let mut test_array:[i32; 6] = [5, 1, 4, 7, 13, 2];
	let expected_result:[i32; 6] = [1, 2, 4, 5, 7, 13];

	bubble_sort(&mut test_array);

	assert_eq!(expected_result, test_array);
}

fn main() {
	test();
}
