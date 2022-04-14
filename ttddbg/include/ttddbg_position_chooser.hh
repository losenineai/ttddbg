#pragma once

#include <vector>
#include <functional>

#include <pro.h>
#include <kernwin.hpp>

#include <Windows.h>
#include "../../ttd-bindings/TTD/TTD.hpp"

namespace ttddbg {
	class PositionChooser : public chooser_t {
	public:
		PositionChooser() = default;
		PositionChooser(std::shared_ptr<TTD::Cursor>);

		void setCursor(std::shared_ptr<TTD::Cursor>);
		
		// Overrides
		size_t get_count() const override;
		void get_row(qstrvec_t* out, int* out_icon, chooser_item_attrs_t* out_attrs, size_t n) const override;
		ea_t get_ea(size_t) const override;
		cbret_t ins(ssize_t) override;
		cbret_t del(size_t) override;

	private:
		std::vector<std::pair<std::string, TTD::Position>> m_positions;

		std::shared_ptr<TTD::Cursor> m_cursor;
	};
}