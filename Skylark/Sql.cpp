#include "Skylark.h"

struct sFieldsToRenderer : public FieldOperator {
	Renderer& http;

	void Field(const char *name, Ref f) {
		http(name, f);
	}
	
	sFieldsToRenderer(Renderer& http) : http(http) {}
};

Renderer& Renderer::operator()(Fields rec)
{
	sFieldsToRenderer x(*this);
	rec(x);
	return *this;
}

Renderer& Renderer::operator()(const Sql& sql)
{
	int n = sql.GetColumns();
	for(int i = 0; i < n; i++)
		(*this)(sql.GetColumnInfo(i).name, sql[i]);
	return *this;
}

SqlUpdate Renderer::Update(SqlId table)
{
	Vector<String> col = GetSchColumns(~table);
	SqlUpdate u(table);
	for(int i = 0; i < col.GetCount(); i++) {
		String c = col[i];
		int q = var.Find(c);
		if(q < 0)
			q = var.Find(ToLower(c));
		if(q >= 0)
			u(c, var[q]);
	}
	return u;
}

SqlInsert Renderer::Insert(SqlId table)
{
	Vector<String> col = GetSchColumns(~table);
	SqlInsert y(table);
	for(int i = 0; i < col.GetCount(); i++) {
		String c = col[i];
		int q = var.Find(c);
		if(q < 0)
			q = var.Find(ToLower(c));
		if(q >= 0)
			y(c, var[q]);
	}
	return y;
}
