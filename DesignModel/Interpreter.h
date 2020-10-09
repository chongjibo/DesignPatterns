#pragma once
#include <iostream>
#include <string>
#include <vector>
//抽象表达式类
class AbstractNode
{
public:
	AbstractNode(){}
	virtual char interpret() = 0;
};

//终结符表达式：值节点
class ValueNode : public AbstractNode
{
public:
	ValueNode(){}
	ValueNode(int i)
	{
		_value = i;
	}

	char interpret()
	{
		return _value;
	}
private:
	int _value;

};

//终结符表达式：运算节点
class OperatorNode : public AbstractNode
{
public:
	OperatorNode(){}
	OperatorNode(std::string iop)
	{
		_op = iop;
	}

	char interpret()
	{
		if (_op == "and")
			return '&';
		else if (_op == "or")
			return '|';
		else
			return 0;
	}

private:
	std::string _op;
};

//句子节点：非终结符表达式
class SentenceNode : public AbstractNode
{
public:
	SentenceNode(){}
	SentenceNode(AbstractNode *leftNode, AbstractNode *rightNode, AbstractNode *opNode) :
		_leftNode(leftNode),_rightNode(rightNode), _opNode(opNode)
	{
	}

	char interpret()
	{
		if (_opNode->interpret() == '&')
			return _leftNode->interpret() & _rightNode->interpret();
		else if(_opNode->interpret() == '|')
			return _leftNode->interpret() | _rightNode->interpret();

		return 0;
	}

private:
	AbstractNode *_leftNode;
	AbstractNode *_rightNode;
	AbstractNode *_opNode;
};

static std::vector<std::string> splitstr(const std::string& str, char tag)
{
	std::vector<std::string>  li;
	std::string subStr;

	//遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
	//遍历结束之后即可得到切割后的字符串数组
	for (size_t i = 0; i < str.length(); i++)
	{
		if (tag == str[i]) //完成一次切割
		{
			if (!subStr.empty())
			{
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else //将i位置的字符放入子串
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty()) //剩余的子串作为最后的子字符串
	{
		li.push_back(subStr);
	}

	return li;
}

class Handler
{
public:
	Handler(){}
	void setInput(std::string input)
	{
		_input = input;
	}

	void handle()
	{
		AbstractNode *left;
		AbstractNode *right;
		AbstractNode *op;
		AbstractNode *sentence;

		std::string input = _input;
		std::vector<std::string> inputList;
		inputList = splitstr(input, ' ');
		for (int i = 0; i < inputList.size() - 2; i += 2)
		{
			left = new ValueNode(*(inputList[i].c_str()));
			op = new OperatorNode(inputList[i + 1]);
			right = new ValueNode(*(inputList[i + 2].c_str()));

			sentence = new SentenceNode(left, right, op);
			inputList[i + 2] = std::string(1, sentence->interpret());
		}

		std::string tmpRes = inputList[inputList.size() - 1];
		if (tmpRes == "1")
			result = '1';
		else if(tmpRes == "0")
			result = '0';
		else
			result = '-1';

		outPut();
	}

	void outPut()
	{
		std::cout << _input << " = " << result << std::endl;
	}
private:
	std::string _input;
	char result;
};