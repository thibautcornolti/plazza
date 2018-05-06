/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** plazza
*/

#pragma once

#include <algorithm>
#include <functional>
#include <memory>

#include "Slave.hpp"
#include "TaskPusherizer.hpp"

namespace Plazza {
	class SlavePool : public TaskPusherizer {
	public:
		SlavePool(unsigned, const std::string &,
			const std::function<void(void)> &);
		~SlavePool();

		void pushTask(Task);
		void createSlave();
		Slave &getBestSlave();
		unsigned getLoad();
		std::vector<std::vector<size_t>> getSummaryLoad();
		std::vector<std::vector<Plazza::Task>> getSummaryTask();
		void exit();

	protected:
	private:
		int _socket;
		unsigned _workerCount;
		std::vector<std::unique_ptr<Slave>> _slaves;
		std::string _loggerName;
		std::function<void(void)> _atFork;
	};
};
