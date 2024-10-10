package SPPYAD.PR2;

import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Stream;

public class PR2
{
    static class Human implements Comparable<Human>
    {
        private int age;
        private String firstName;
        private String lastName;
        private final LocalDate birthDate;
        private int weight;

        public Human(int age, String firstName, String lastName, LocalDate birthDate, int weight)
        {
            this.age = age;
            this.firstName = firstName;
            this.lastName = lastName;
            this.birthDate = birthDate;
            this.weight = weight;
        }

        public int getAge() {
            return age;
        }

        public String getFirstName() {
            return firstName;
        }

        public String getLastName() {
            return lastName;
        }

        public LocalDate getBirthDate() {
            return birthDate;
        }

        public int getWeight() {
            return weight;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Human human = (Human) o;
            return age == human.age && weight == human.weight && Objects.equals(firstName, human.firstName) &&
                    Objects.equals(lastName, human.lastName) && Objects.equals(birthDate, human.birthDate);
        }

        @Override
        public int hashCode() {
            return Objects.hash(age, firstName, lastName, birthDate, weight);
        }

        @Override
        public int compareTo(Human o) {
            return this.weight - o.weight;
        }

        @Override
        public String toString() {
            return "Human{" +
                    "age=" + age +
                    ", firstName='" + firstName + '\'' +
                    ", lastName='" + lastName + '\'' +
                    ", birthDate=" + birthDate +
                    ", weight=" + weight +
                    '}' + "\n";
        }
    }
    public static void main(String[] args)
    {
        try (FileReader reader = new FileReader("src/SPPYAD/PR2/Names.txt"))
        {
            Scanner sc = new Scanner(reader);
            List<Human> array = new ArrayList<>();
            for (int i = 0; i < 7 || sc.hasNext(); i++)
                array.add(new Human((i << 1) + 15, sc.next(), sc.next(), LocalDate.of(1999 + 2 * i, i + 2, i + 3), 40 + 10 * i));
            System.out.println(array);
            Stream<Human> str = array.stream();
            str.limit(5).sorted().filter(e -> e.getWeight() < 60).forEach(e -> System.out.println("Имя: " + e.getFirstName() + "   Фамилия: " + e.getLastName()));
        }
        catch (IOException exc)
        {
            System.exit(1);
        }
    }
}