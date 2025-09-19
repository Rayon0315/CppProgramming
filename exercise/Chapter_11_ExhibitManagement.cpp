#include<iostream>
#include<vector>
#include<string>
#include<exception>
using namespace std;

class Exhibit {
public:
    string name;
    string description;

    Exhibit (const string &nameInput, const string &descriptionInput)
    : name(nameInput), description(descriptionInput) {}

    virtual void display() const = 0;
    virtual ~Exhibit () {}
};

class DocumentExhibit : public Exhibit {
public:
    DocumentExhibit (const string &nameInput, const string &descriptionInput)
    : Exhibit(nameInput, descriptionInput) {}

    void display() const {
        cout << "文献: " << name << "---" << description << endl;
    }
};
class ImageExhibit : public Exhibit {
public:
    ImageExhibit (const string &nameInput, const string &descriptionInput)
    : Exhibit(nameInput, descriptionInput) {}

    void display() const {
        cout << "图片: " << name << "---" << description << endl;
    }
};
class ArtifactExhibit : public Exhibit {
public:
    ArtifactExhibit (const string &nameInput, const string &descriptionInput)
    : Exhibit(nameInput, descriptionInput) {}

    void display() const {
        cout << "实物: " << name << "---" << description << endl;
    }
};

class ExhibitManageSystem {
private:
    vector<Exhibit*> exhibits;

public:
    template<typename T, typename... Args>
    void addExhibit(Args... args) {
        exhibits.push_back(new T(args...));
    }

    ~ExhibitManageSystem () {
        for (auto exhibit: exhibits) {
            delete exhibit;
        }
    }

    void displayAll() const {
        for (auto exhibit: exhibits) {
            exhibit -> display();
        }
    }

    void displayByType(const string &type) const {
        bool found = false;
        for (auto exhibit: exhibits) {
            if (type == "文献" && dynamic_cast<const DocumentExhibit*>(exhibit) ||
                type == "图片" && dynamic_cast<const ImageExhibit*>(exhibit) ||
                type == "实物" && dynamic_cast<const ArtifactExhibit*>(exhibit)) {
                    exhibit -> display();
                    found = true;
                }
        }
        if (!found) {
            cout << "未找到指定类型: " << type << "!" << endl;
        }
    }
};

int main() {
    ExhibitManageSystem sys;
    sys.addExhibit<DocumentExhibit>("Book", "A book");
    sys.addExhibit<DocumentExhibit>("Letter", "A letter");
    sys.addExhibit<ImageExhibit>("Photo", "A photo");
    //sys.addExhibit<ArtifactExhibit>("Bowl", "A bowl");

    sys.displayAll();
    sys.displayByType("文献");
    sys.displayByType("实物");
    return 0;
}