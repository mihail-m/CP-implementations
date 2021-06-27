// Selection sort
// Complexity: O(n^2)

fn selection_sort(array: &mut [i32]) {
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

fn test() {
	let mut test_array:[i32; 6] = [5, 1, 4, 7, 13, 2];
	let expected_result:[i32; 6] = [1, 2, 4, 5, 7, 13];

	selection_sort(&mut test_array);

	assert_eq!(expected_result, test_array);
}

fn main() {
	test();
}
