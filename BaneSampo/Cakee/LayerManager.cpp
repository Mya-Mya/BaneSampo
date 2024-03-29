#include "LayerManager.h"

LayerManager::LayerManager()
{
}

LayerManager::~LayerManager()
{
}

void LayerManager::mainLoop()
{
	//νvΏΜ Α½Layerπν
	if (!deleteQue.empty()) {
		for(Layer* target:deleteQue){
			layerList.remove(target);
			delete target;
		}
		deleteQue.clear();
	}
	for (itr = layerList.begin(); itr != layerList.end(); itr++) {
		(*itr)->update();
		if (!(*itr)->canUndersUpdate())break;
	}
	for (rItr = layerList.rbegin(); rItr != layerList.rend(); rItr++) {
		(*rItr)->draw();
	}	
}

void LayerManager::addLayer(Layer*you,Layer * newLayer, StackingMode sm)
{
	switch (sm)
	{
	case Top:
		layerList.push_front(newLayer);
		break;
	case Above:
		for (itr = layerList.begin(); itr != layerList.end(); itr++) {
			if (*itr == you) {
				layerList.insert(itr, newLayer);
				break;
			}
		}
		break;
	case Bottom:
		layerList.push_back(newLayer);
		break;
	default:
		break;
	}
	
}

void LayerManager::requireDelete(Layer * you)
{
	deleteQue.push_back(you);
}

void LayerManager::requireSwap(Layer * you, Layer * another)
{
	addLayer(you, another, StackingMode::Above);
	requireDelete(you);
}
