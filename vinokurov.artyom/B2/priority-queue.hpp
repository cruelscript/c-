#ifndef B2_PRIORITY_QUEUE_HPP
#define B2_PRIORITY_QUEUE_HPP

#include <array>
#include <list>

template<typename T>
class PriorityQueue
{
public:
  enum Priority
  {
    LOW,
    NORMAL,
    HIGH
  };

  void enqueue(const T& element, Priority);
  T dequeue();
  void accelerate();
  bool isEmpty() const noexcept;

private:
  std::array<std::list<T>, 3> priorityLists_;
};

template<typename T>
void PriorityQueue<T>::enqueue(const T& element, PriorityQueue::Priority priority)
{
  priorityLists_[priority].push_back(element);
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
  if(this->isEmpty())
  {
    throw std::out_of_range("PriorityQueue: Error. Queue underflow.");
  }

  Priority priority = Priority::LOW;

  if(!priorityLists_[Priority::HIGH].empty())
  {
    priority = Priority::HIGH;
  }
  else if(!priorityLists_[Priority::NORMAL].empty())
  {
    priority = Priority::NORMAL;
  }

  T element = priorityLists_[priority].front();
  priorityLists_[priority].pop_front();

  return element;
}

template<typename T>
void PriorityQueue<T>::accelerate()
{
  priorityLists_[Priority::HIGH].splice(priorityLists_[Priority::HIGH].end(), priorityLists_[Priority::LOW]);
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const noexcept
{
  return priorityLists_[Priority::HIGH].empty() &&
    priorityLists_[Priority::NORMAL].empty() &&
    priorityLists_[Priority::LOW].empty();
}

#endif //B2_PRIORITY_QUEUE_HPP
