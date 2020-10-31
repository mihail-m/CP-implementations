package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

public class BasicDataStructuresTest {

    @Test
    public void testLinkedList() {
        LinkedList<Integer> list = new LinkedList<>();

        list.addToBeginning(1);
        list.addToEnd(5);
        list.insertAt(4,1);
        list.insertAt(19, 2);
        Assert.assertEquals("[1, 4, 19, 5]", list.toString());

        list.reverse();
        Assert.assertEquals("[5, 19, 4, 1]", list.toString());

        list.eraseAt(1);
        list.eraseEnd();
        Assert.assertEquals("[5, 4]", list.toString());
    }

    @Test
    public void testDoublyLinkedList() {
        DoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        list.addToBeginning(1);
        list.addToEnd(5);
        list.insertAt(4,1);
        list.insertAt(19, 2);

        Assert.assertEquals("[1, 4, 19, 5]", list.toString());

        list.reverse();
        Assert.assertEquals("[5, 19, 4, 1]", list.toString());

        list.eraseAt(1);
        list.eraseEnd();
        Assert.assertEquals("[5, 4]", list.toString());
    }

    @Test
    public void testStack() {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(7);
        stack.push(73);
        stack.push(2);

        Assert.assertEquals(2, (int) stack.poll());
        Assert.assertEquals(73, (int) stack.top());
        Assert.assertEquals("[1, 7, 73]", stack.toString());
    }

    @Test
    public void testQueue() {
        Queue<Integer> queue = new Queue<>();

        queue.push(1);
        queue.push(7);
        queue.push(73);
        queue.push(2);

        Assert.assertEquals(1, (int) queue.poll());
        Assert.assertEquals(7, (int) queue.front());
        Assert.assertEquals("[7, 73, 2]", queue.toString());
    }

    @Test
    public void testMinQueue() {
        MinQueue<Integer> queue = new MinQueue<>();

        queue.push(9);
        Assert.assertEquals(9, (int) queue.minimum());

        queue.push(7);
        Assert.assertEquals(7, (int) queue.minimum());

        queue.push(2);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.push(73);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.push(5);
        Assert.assertEquals(2, (int) queue.minimum());

        queue.pop();
        queue.pop();
        queue.pop();
        Assert.assertEquals(5, (int) queue.minimum());
    }

    @Test
    public void testMinStack() {
        MinStack<Integer> stack = new MinStack<>();

        stack.push(3);
        Assert.assertEquals(3, (int) stack.minimum());

        stack.push(7);
        Assert.assertEquals(3, (int) stack.minimum());

        stack.push(2);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.push(73);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.push(5);
        Assert.assertEquals(2, (int) stack.minimum());

        stack.pop();
        stack.pop();
        stack.pop();
        Assert.assertEquals(3, (int) stack.minimum());
    }

    @Test
    public void testHashTable() {
        HashTable<String, Integer> map = new HashTable<>();

        map.put("1", 1);
        map.put("2", 2);
        map.put("3", 3);
        map.put("4", 4);

        Assert.assertNull(map.get("7"));
        Assert.assertEquals(2, (int) map.get("2"));

        map.erase("3");

        Assert.assertEquals("{(1, 1), (2, 2), (4, 4)}", map.toString());
    }
    
    @Test
    public void testMinHeap() {
        Heap<Integer> heap = new Heap<>(Integer::compare);
        heap.push(7);
        heap.push(5);

        Assert.assertEquals(new Integer(5), heap.top());

        heap.push(6);
        heap.push(3);

        Assert.assertEquals(new Integer(3), heap.poll());
        Assert.assertEquals(new Integer(5), heap.poll());
        Assert.assertEquals(new Integer(6), heap.poll());
        Assert.assertEquals(new Integer(7), heap.poll());
    }

    @Test
    public void testMaxHeap() {
        Heap<Integer> heap = new Heap<>((integer, t1) -> Integer.compare(t1, integer));
        heap.push(7);
        heap.push(5);

        Assert.assertEquals(new Integer(7), heap.top());

        heap.push(9);
        heap.push(3);

        Assert.assertEquals(new Integer(9), heap.poll());
        Assert.assertEquals(new Integer(7), heap.poll());
        Assert.assertEquals(new Integer(5), heap.poll());
        Assert.assertEquals(new Integer(3), heap.poll());
    }
}
