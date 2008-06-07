#include "GridCtrl.h"

NAMESPACE_UPP

/*
bool GridCtrl::operator<(const Vector<Value>& a, const Vector<Value>& b)
{
	for(int i = 0; i < SortOrder.GetCount(); i++)
	{
		if(sortMode)
			return (StdValueCompare((*a.items)[a.id][sortCol].val, (*b.items)[b.id][sortCol].val, 0) < 0);
		else
			return a.id < b.id;

	}
}
*/

void GridCtrl::GSort(int scol)
{
	int col;

	int cnt = sortOrder.GetCount();

	if(cnt == 0)
		return;

	if(scol < 0)
		scol = cnt - 1;

	col = sortOrder[scol];

	//int order = 1;
	int order = hitems[col].sortmode;

	/* dla trybu multisort nie mozna w ten sposob
	   sortowac dla pierwszej kolumny */

	if(cnt > 1 && scol != 0)
	{
		int match = 1;
		int is = fixed_rows;

		for(int i = fixed_rows + 1; i < total_rows; i++)
		{
			int n = vitems[i].id;
			int m = vitems[is].id;

			bool found = true;
			for(int j = 0; j < scol; j++)
			{
				int k = sortOrder[j];
				if(items[n][k].val != items[m][k].val)
				{
					found = false;
					break;
				}
			}

			if(found)
			{
				match++;
				continue;
			}
			else
			{
				if(match > 1)
					GSort(col, order, is, match);

				match = 1;
				is = i;
			}
		}
		if(match > 1)
			GSort(col, order, is, match);
	}
	else
		GSort(col, order, fixed_rows);

}

void GridCtrl::GSort(int col, int order, int from, int count)
{
	if(count == 0)
		return;

	ItemRect::sortCol = col;
	ItemRect::sortMode = (order != 0);

	VItems::Iterator its, ite;

	its = vitems.Begin() + from;

	if(count < 0)
		ite = vitems.End();
	else
		ite = its + count;

	if(order < 2)
		Upp::Sort(its, ite, StdLess<ItemRect>());
	else
		Upp::Sort(its, ite, StdGreater<ItemRect>());
}


void GridCtrl::Multisort()
{
	GSort(-1, 0, fixed_rows);
	for(int i = 0; i < sortOrder.GetCount(); i++)
		GSort(i);
}

int GridCtrl::InMultisort(int col)
{
	for(int i = 0; i < sortOrder.GetCount(); i++)
		if(col == sortOrder[i])
			return i;

	return -1;
}

bool GridCtrl::ClearMultisort()
{
	if(sortOrder.IsEmpty())
		return false;

	return ClearSorted();
}

bool GridCtrl::ClearSorted()
{
	bool sorted = false;

	for(int i = 0; i < total_cols; i++)
	{
		if(hitems[i].sortMode > 0)
			sorted = true;
		hitems[i].sortmode = 0;
		hitems[i].sortcol = 0;
	}

	return sorted;
}

bool GridCtrl::IsSorted()
{
	return sortOrder.GetCount() > 0 || sortCol >= 0;
}

GridCtrl& GridCtrl::Sort(int sort_col, int sort_mode, bool multisort, bool repaint)
{
	int col = GetIdCol(sort_col + fixed_cols);
	if(col < 0)
		return *this;

	if(!multisort)
	{
		sortOrder.Clear();
		ClearSorted();
	}

	sortOrder.Add(col);

	hitems[col].sortmode = sort_mode;
	hitems[col].sortcol = sortOrder.GetCount();
	GSort();

	UpdateCursor();

	if(repaint)
		Repaint(false, true);
	return *this;
}

GridCtrl& GridCtrl::Sort(Id id, int sort_mode, bool multisort, bool repaint)
{
	return Sort(aliases.Get(id) - fixed_cols, sort_mode, multisort, repaint);
}

GridCtrl& GridCtrl::MultiSort(int sort_col, int sort_mode)
{
	return Sort(sort_col, sort_mode, true);
}

GridCtrl& GridCtrl::MultiSort(Id id, int sort_mode)
{
	return Sort(aliases.Get(id) - fixed_cols, sort_mode, true);
}

void GridCtrl::ClearSort()
{
	Sort(0, SORT_ID);
}

END_UPP_NAMESPACE
