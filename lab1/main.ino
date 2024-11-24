// Состояние системы
bool buttonWasPressed = false;
bool ledEnabled = false; // Включена ли мигалка
bool redLedState = true; // Состояние красного светодиода
unsigned long lastToggleTime = 0; // Время последнего переключения

void setup() {
  pinMode(13, OUTPUT);     // Красный светодиод
  pinMode(12, OUTPUT);     // Синий светодиод
  pinMode(2, INPUT_PULLUP); // Кнопка
}

void loop() {
  // Обработка кнопки
  if (digitalRead(2) == LOW) {
    buttonWasPressed = true; // Кнопка нажата
  } else if (digitalRead(2) == HIGH && buttonWasPressed) {
    // Если кнопка была нажата, переключаем состояние мигалки
    ledEnabled = !ledEnabled;
    buttonWasPressed = false; // Сбрасываем флаг кнопки

    // Выключаем светодиоды, если мигалка выключена
    if (!ledEnabled) {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
    }
  }

  // Если мигалка включена
  if (ledEnabled) {
    // Управляем миганием светодиодов с интервалом 500 мс
    if (millis() - lastToggleTime >= 500) {
      lastToggleTime = millis(); // Обновляем таймер
      digitalWrite(13, redLedState);      // Устанавливаем состояние красного светодиода
      digitalWrite(12, !redLedState);     // Противоположное состояние для синего
      redLedState = !redLedState;         // Переключаем состояние
    }
  }
}
