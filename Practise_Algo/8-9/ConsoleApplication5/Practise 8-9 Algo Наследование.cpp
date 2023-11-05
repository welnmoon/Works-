#include <iostream>
#include <unordered_map>

using namespace std;

class Translator {
public:
    Translator() {
        dictionary["hi"] = "Привет";
        dictionary["cat"] = "Кот";
    }

    void addTranslation(const string& word, const string& translation) {
        dictionary[word] = translation;
    }

    string translate(const string& word) {
        if (dictionary.find(word) != dictionary.end()) {
            return dictionary[word];
        }
        else {
            return "Перевод не найден";
        }
    }

    virtual void print() {
        cout<<
    }

protected:
    unordered_map<string, string> dictionary;
};

class CustomTranslator : public Translator {
public:
    CustomTranslator() {
        dictionary["dog"] = "Собака";
        dictionary["bird"] = "Птица";
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    CustomTranslator customTranslator;
    cout << "Перевод слова 'hi': " << customTranslator.translate("hi") << endl;
    cout << "Перевод слова 'cat': " << customTranslator.translate("cat") << endl;
    cout << "Перевод слова 'dog': " << customTranslator.translate("dog") << endl;
    cout << "Перевод слова 'bird': " << customTranslator.translate("bird") << endl;

    customTranslator.addTranslation("fish", "Рыба");
    cout << "Перевод слова 'fish': " << customTranslator.translate("fish") << endl;

    return 0;
}

