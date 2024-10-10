package SPPYAD.PR3;

import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.concurrent.Semaphore;

class SemaphoreSet<E> implements Set<E>
{
    private final Semaphore semaphore;
    private final Set<E> set = new HashSet<>();

    public SemaphoreSet(Semaphore semaphore) {
        this.semaphore = semaphore;
    }

    @Override
    public int size() {
        return set.size();
    }

    @Override
    public boolean isEmpty() {
        return set.isEmpty();
    }

    @Override
    public boolean contains(Object o) {
        return set.contains(o);
    }

    @Override
    public Iterator<E> iterator() {
        return set.iterator();
    }

    @Override
    public Object[] toArray() {
        return set.toArray();
    }

    @Override
    public <T> T[] toArray(T[] a) {
        return set.toArray(a);
    }

    @Override
    public boolean add(E e) {
        if (set.contains(e)) {
            return false;
        }
        try {
            semaphore.acquire();
            set.add(e);
            System.out.println("Добавлено " + e + " " + Thread.currentThread().getName());
            semaphore.release();
            return true;
        } catch (InterruptedException ex) {
            System.exit(1);
        }
        return false;
    }

    @Override
    public boolean remove(Object o) {
        return set.remove(o);
    }

    @Override
    public boolean containsAll(Collection<?> c) {
        return set.containsAll(c);
    }

    @Override
    public boolean addAll(Collection<? extends E> c) {
        return set.addAll(c);
    }

    @Override
    public boolean retainAll(Collection<?> c) {
        return set.retainAll(c);
    }

    @Override
    public boolean removeAll(Collection<?> c) {
        return set.removeAll(c);
    }

    @Override
    public void clear() {
        set.clear();
    }
}
public class SemaphoreTest
{
    public static void main(String[] args) throws InterruptedException {
        Semaphore sm = new Semaphore(2);
        SemaphoreSet<String> strings = new SemaphoreSet<>(sm);
        Thread tr1 = new Thread(() -> {
            for (int i = 0; i < 30; i++)
                strings.add(i + "");
        });
        Thread tr2 = new Thread(() -> {
            for (int i = 0; i < 30; i++)
                strings.add(i + "");
        });
        tr1.start();
        tr2.start();
        Thread.sleep(300);
        System.out.println("Элементов в Set: " + strings.size() + " " + Thread.currentThread().getName());
        strings.forEach(System.out::println);
    }
}
