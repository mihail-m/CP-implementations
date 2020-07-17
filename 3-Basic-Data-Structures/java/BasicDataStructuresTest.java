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
}
