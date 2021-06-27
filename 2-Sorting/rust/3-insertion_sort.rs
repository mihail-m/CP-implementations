// Insertion sort
// Complexity: O(n^2)

fn insertion_sort(array: &mut [i32]) {
	for i in 1..array.len() {

		let mut j = i;

		while j > 0 && array[j] < array[j - 1] {
			array.swap(j, j - 1);
			j = j - 1
		}
	}
}

fn test() {
	let mut test_array:[i32; 6] = [5, 1, 4, 7, 13, 2];
	let expected_result:[i32; 6] = [1, 2, 4, 5, 7, 13];

	insertion_sort(&mut test_array);

	assert_eq!(expected_result, test_array);
}

fn main() {
	test();
}
