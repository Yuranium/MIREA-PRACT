package SPPYAD.PR3;

import java.util.*;
import java.util.function.UnaryOperator;

class MyArrayList<E> implements List<E>
{
    private final List<E> list = new ArrayList<>();
    @Override
    public synchronized int size() {
        return list.size();
    }

    @Override
    public synchronized boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public synchronized boolean contains(Object o) {
        return list.contains(o);
    }

    @Override
    public synchronized Iterator<E> iterator() {
        return list.iterator();
    }

    @Override
    public synchronized Object[] toArray() {
        return list.toArray();
    }

    @Override
    public synchronized <T> T[] toArray(T[] a) {
        return list.toArray(a);
    }

    @Override
    public synchronized boolean add(E e) {
        return list.add(e);
    }

    @Override
    public synchronized boolean remove(Object o) {
        return list.remove(o);
    }

    @Override
    public synchronized boolean containsAll(Collection<?> c) {
        return new HashSet<>(list).containsAll(c);
    }

    @Override
    public synchronized boolean addAll(Collection<? extends E> c) {
        return list.addAll(c);
    }

    @Override
    public synchronized boolean addAll(int index, Collection<? extends E> c) {
        return list.addAll(c);
    }

    @Override
    public synchronized boolean removeAll(Collection<?> c) {
        return false;
    }

    @Override
    public synchronized boolean retainAll(Collection<?> c) {
        return list.retainAll(c);
    }

    @Override
    public synchronized void clear() {
        list.clear();
    }

    @Override
    public synchronized E get(int index) {
        return null;
    }

    @Override
    public synchronized E set(int index, E element) {
        return null;
    }

    @Override
    public synchronized void add(int index, E element) {
        list.add(index, element);
    }

    @Override
    public synchronized E remove(int index) {
        return list.remove(index);
    }

    @Override
    public synchronized int indexOf(Object o) {
        return list.indexOf(o);
    }

    @Override
    public synchronized int lastIndexOf(Object o) {
        return list.lastIndexOf(o);
    }

    @Override
    public synchronized ListIterator<E> listIterator() {
        return list.listIterator();
    }

    @Override
    public synchronized ListIterator<E> listIterator(int index) {
        return list.listIterator(index);
    }

    @Override
    public synchronized List<E> subList(int fromIndex, int toIndex) {
        return list.subList(fromIndex, toIndex);
    }

    @Override
    public synchronized void replaceAll(UnaryOperator<E> operator) {
        list.replaceAll(operator);
    }

    @Override
    public synchronized void sort(Comparator<? super E> c) {
        list.sort(c);
    }

    @Override
    public synchronized Spliterator<E> spliterator() {
        return list.spliterator();
    }
}
public class PR3
{
    public static void main(String[] args) throws InterruptedException {
        List<Integer> arrayList = new MyArrayList<>();
        Runnable rn1 = (() -> {
            for (int i = 0; i < 500; i++)
                arrayList.add(i);
        });
        Runnable rn2 = (() -> {
            for (int i = 0; i < 500; i++)
                arrayList.add(i);
        });
        Runnable rn3 = (() -> {
            for (int i = 0; i < 500; i++)
                arrayList.add(i);
        });
        Thread thread1 = new Thread(rn1);
        Thread thread2 = new Thread(rn2);
        thread1.start();
        thread2.start();
        Thread.sleep(1);
        System.out.println("Потокобезопасная коллекция.\nЭлементов добавлено в лист: " + arrayList.size());
    }
}