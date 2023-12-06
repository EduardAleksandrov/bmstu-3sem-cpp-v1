#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Класс, представляющий событие
class Event 
{
public:
    // Метод, вызываемый при возникновении события
    virtual void handleEvent() = 0;
};

// Интерфейс для классов-подписчиков
class Subscriber 
{
public:
    // Метод, вызываемый при доставке события
    virtual void notify(Event* event) = 0;
};

// Класс-издатель
class Publisher 
{
public:
    // Метод для добавления подписчиков
    void subscribe(Subscriber* subscriber) 
    {
        subscribers.push_back(subscriber);
    }

    // Метод для удаления подписчиков
    void unsubscribe(Subscriber* subscriber) 
    {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
    }

    // Метод для генерации события
    void publish(Event* event) 
    {
        for (auto subscriber : subscribers) 
        {
            subscriber->notify(event);
        }
    }

private:
    vector<Subscriber*> subscribers;
};

// Конкретный класс-событие
class ButtonClickEvent : public Event 
{
public:
    void handleEvent() override 
    {
        cout << "Button click event handled" << endl;
    }
};

// Конкретный класс-подписчик
class LoggingSubscriber : public Subscriber 
{
public:
    void notify(Event* event) override 
    {
        cout << "Event received by logging subscriber: ";
        event->handleEvent();
    }
};

int main() 
{
    // Создание объектов
    Publisher publisher;
    ButtonClickEvent buttonClickEvent;
    LoggingSubscriber loggingSubscriber;

    // Добавление подписчика
    publisher.subscribe(&loggingSubscriber);

    // Генерация события
    publisher.publish(&buttonClickEvent);

    // Удаление подписчика
    publisher.unsubscribe(&loggingSubscriber);

    return 0;
}