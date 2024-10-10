package SPPYAD.PR1;

import java.util.Comparator;
@FunctionalInterface
interface MyComparator extends Comparator<Integer>
{
    @Override
    int compare(Integer o1, Integer o2);
}
public class PR1
{
    public static void main(String[] args) {
        MyComparator comparator = (a, b) -> a - b;
        System.out.println("Результат метода: " + comparator.compare(10, 20));
        MyComparator comparator1 = (x, y) -> x * x - y * y;
        System.out.println("Результат метода: " + comparator1.compare(5, 10));
    }
}
