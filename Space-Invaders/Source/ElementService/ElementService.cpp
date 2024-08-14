#include"../../Header/Elements/ElementService.h"

namespace Element
{
	ElementService::ElementService()
	{

	}

	ElementService::~ElementService()
	{
		destroy();
	}

	void ElementService::initialize()
	{
		for (int i = 0;i < bunker_data_list.size();i++)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();

			bunker_controller->initialize(bunker_data_list[i]);
			bunker_list.push_back(bunker_controller);
		}
	}

	void ElementService::update()
	{
		for (int i = 0;i < bunker_list.size();i++)bunker_list[i]->update();
	}

	void ElementService::render()
	{
		for (int i = 0 ; i < bunker_list.size(); i++)bunker_list[i]->render();
	}

	void ElementService::destroy()
	{
		for (int i = 0;i < bunker_list.size();i++)delete(bunker_list[i]);
	}

	void ElementService::reset()
	{
		destroy();
	}
}