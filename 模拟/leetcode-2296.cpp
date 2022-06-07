class TextEditor {
public:
    string str;
    int idx;
    TextEditor() {
        str = "";
        idx = 0;
    }
    
    void addText(string text) {
        str.insert(idx, text);
        idx += text.length();
    }
    
    int deleteText(int k) {
        int n = min(idx, k);
        idx -= n;
        str.erase(idx, n);
        return n;
    }
    
    string cursorLeft(int k) {
        idx = max(0, idx-k);
        int l = max(0, idx-10);
        return str.substr(l, idx-l);
    }
    
    string cursorRight(int k) {
        idx = min( (int) str.length(), idx+k);
        int l = max(0, idx-10);
        return str.substr(l, idx-l);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */