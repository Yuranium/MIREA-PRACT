package SPPYAD.PR4;

import java.util.ArrayDeque;
import java.util.Queue;

class SimpleExecutorService {
    private final Thread[] threads;
    private final Queue<Runnable> taskQueue;

    public SimpleExecutorService(int numThreads) {
        this.threads = new Thread[numThreads];
        this.taskQueue = new ArrayDeque<>();

        for (int i = 0; i < numThreads; i++) {
            threads[i] = new WorkerThread();
            threads[i].start();
        }
    }

    public void execute(Runnable task) {
        synchronized (taskQueue) {
            taskQueue.add(task);
            taskQueue.notify();
        }
    }

    private class WorkerThread extends Thread {
        @Override
        public void run() {
            Runnable task;
            while (true) {
                synchronized (taskQueue) {
                    while (taskQueue.isEmpty()) {
                        try {
                            taskQueue.wait();
                        } catch (InterruptedException e) {
                            Thread.currentThread().interrupt();
                            return;
                        }
                    }
                    task = taskQueue.poll();
                }
                try {
                    task.run();
                } catch (RuntimeException e) {
                    System.exit(1);
                }
            }
        }
    }
}

public class PR4
{
    public static void main(String[] args) {
        SimpleExecutorService executorService = new SimpleExecutorService(3);
        // Поступают задачи на выполнение
        for (int i = 0; i < 10; i++) {
            int taskNumber = i;
            executorService.execute(() -> {
                System.out.println("Задача " + taskNumber + " выполняется потоком " + Thread.currentThread().getName());
                try {
                    Thread.sleep(1000); // Имитируем выполнение задачи
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("Задача " + taskNumber + " была выполнена");
            });
        }
    }
}