package basic.data.structures;

import org.junit.Assert;
import org.junit.Test;

import javax.persistence.criteria.CriteriaBuilder;

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

        Assert.assertEquals(2, (int) stack.pop());
        Assert.assertEquals(73, (int) stack.top());
        Assert.assertEquals("[1, 7, 73]", stack.toString());
    }
}
