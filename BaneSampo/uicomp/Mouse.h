#pragma once
class Mouse {

	Mouse();

	virtual ~Mouse() {}
	Mouse(const Mouse&r) {}
	Mouse&operator=(const Mouse&r) {}
public:
	static Mouse*Instance() {
		static Mouse inst;
		return&inst;
	}
	bool Update();	//更新
	int GetPressingCount(int keyCode);//keyCodeのキーが押されているフレーム数を取得
	int GetReleasingCount(int keyCode);//keyCodeのキーが離されているフレーム数を取得
	int GetX();
	int GetY();
	const static int LEFT = 0;
	const static int RIGHT = 1;
	const static int MIDDLE = 2;

private:
	const static int BUTTON_NUM = 8;
	int mKeyPressingCount[BUTTON_NUM];//押されカウンタ
	int mKeyReleasingCount[BUTTON_NUM];//離されカウンタ
	int mX, mY;

	bool IsAvailableCode(int keyCode);//keyCodeが有効なキー番号か問う
};