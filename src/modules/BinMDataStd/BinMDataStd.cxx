/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_BinMDataStd(py::module &);
void bind_BinMDataStd_AsciiStringDriver(py::module &);
void bind_BinMDataStd_BooleanArrayDriver(py::module &);
void bind_BinMDataStd_BooleanListDriver(py::module &);
void bind_BinMDataStd_ByteArrayDriver(py::module &);
void bind_BinMDataStd_CommentDriver(py::module &);
void bind_BinMDataStd_DirectoryDriver(py::module &);
void bind_BinMDataStd_ExpressionDriver(py::module &);
void bind_BinMDataStd_ExtStringArrayDriver(py::module &);
void bind_BinMDataStd_ExtStringListDriver(py::module &);
void bind_BinMDataStd_IntegerArrayDriver(py::module &);
void bind_BinMDataStd_IntegerDriver(py::module &);
void bind_BinMDataStd_IntegerListDriver(py::module &);
void bind_BinMDataStd_IntPackedMapDriver(py::module &);
void bind_BinMDataStd_NamedDataDriver(py::module &);
void bind_BinMDataStd_NameDriver(py::module &);
void bind_BinMDataStd_NoteBookDriver(py::module &);
void bind_BinMDataStd_RealArrayDriver(py::module &);
void bind_BinMDataStd_RealDriver(py::module &);
void bind_BinMDataStd_RealListDriver(py::module &);
void bind_BinMDataStd_ReferenceArrayDriver(py::module &);
void bind_BinMDataStd_ReferenceListDriver(py::module &);
void bind_BinMDataStd_RelationDriver(py::module &);
void bind_BinMDataStd_TickDriver(py::module &);
void bind_BinMDataStd_TreeNodeDriver(py::module &);
void bind_BinMDataStd_UAttributeDriver(py::module &);
void bind_BinMDataStd_VariableDriver(py::module &);

PYBIND11_MODULE(BinMDataStd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.BinObjMgt");
py::module::import("OCCT.TDF");

bind_BinMDataStd(mod);
bind_BinMDataStd_AsciiStringDriver(mod);
bind_BinMDataStd_BooleanArrayDriver(mod);
bind_BinMDataStd_BooleanListDriver(mod);
bind_BinMDataStd_ByteArrayDriver(mod);
bind_BinMDataStd_CommentDriver(mod);
bind_BinMDataStd_DirectoryDriver(mod);
bind_BinMDataStd_ExpressionDriver(mod);
bind_BinMDataStd_ExtStringArrayDriver(mod);
bind_BinMDataStd_ExtStringListDriver(mod);
bind_BinMDataStd_IntegerArrayDriver(mod);
bind_BinMDataStd_IntegerDriver(mod);
bind_BinMDataStd_IntegerListDriver(mod);
bind_BinMDataStd_IntPackedMapDriver(mod);
bind_BinMDataStd_NamedDataDriver(mod);
bind_BinMDataStd_NameDriver(mod);
bind_BinMDataStd_NoteBookDriver(mod);
bind_BinMDataStd_RealArrayDriver(mod);
bind_BinMDataStd_RealDriver(mod);
bind_BinMDataStd_RealListDriver(mod);
bind_BinMDataStd_ReferenceArrayDriver(mod);
bind_BinMDataStd_ReferenceListDriver(mod);
bind_BinMDataStd_RelationDriver(mod);
bind_BinMDataStd_TickDriver(mod);
bind_BinMDataStd_TreeNodeDriver(mod);
bind_BinMDataStd_UAttributeDriver(mod);
bind_BinMDataStd_VariableDriver(mod);

}
