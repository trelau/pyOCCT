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

void bind_XmlMDataStd(py::module &);
void bind_XmlMDataStd_AsciiStringDriver(py::module &);
void bind_XmlMDataStd_BooleanArrayDriver(py::module &);
void bind_XmlMDataStd_BooleanListDriver(py::module &);
void bind_XmlMDataStd_ByteArrayDriver(py::module &);
void bind_XmlMDataStd_CommentDriver(py::module &);
void bind_XmlMDataStd_DirectoryDriver(py::module &);
void bind_XmlMDataStd_ExpressionDriver(py::module &);
void bind_XmlMDataStd_ExtStringArrayDriver(py::module &);
void bind_XmlMDataStd_ExtStringListDriver(py::module &);
void bind_XmlMDataStd_IntegerArrayDriver(py::module &);
void bind_XmlMDataStd_IntegerDriver(py::module &);
void bind_XmlMDataStd_IntegerListDriver(py::module &);
void bind_XmlMDataStd_IntPackedMapDriver(py::module &);
void bind_XmlMDataStd_NamedDataDriver(py::module &);
void bind_XmlMDataStd_NameDriver(py::module &);
void bind_XmlMDataStd_NoteBookDriver(py::module &);
void bind_XmlMDataStd_RealArrayDriver(py::module &);
void bind_XmlMDataStd_RealDriver(py::module &);
void bind_XmlMDataStd_RealListDriver(py::module &);
void bind_XmlMDataStd_ReferenceArrayDriver(py::module &);
void bind_XmlMDataStd_ReferenceListDriver(py::module &);
void bind_XmlMDataStd_RelationDriver(py::module &);
void bind_XmlMDataStd_TickDriver(py::module &);
void bind_XmlMDataStd_TreeNodeDriver(py::module &);
void bind_XmlMDataStd_UAttributeDriver(py::module &);
void bind_XmlMDataStd_VariableDriver(py::module &);

PYBIND11_MODULE(XmlMDataStd, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

bind_XmlMDataStd(mod);
bind_XmlMDataStd_AsciiStringDriver(mod);
bind_XmlMDataStd_BooleanArrayDriver(mod);
bind_XmlMDataStd_BooleanListDriver(mod);
bind_XmlMDataStd_ByteArrayDriver(mod);
bind_XmlMDataStd_CommentDriver(mod);
bind_XmlMDataStd_DirectoryDriver(mod);
bind_XmlMDataStd_ExpressionDriver(mod);
bind_XmlMDataStd_ExtStringArrayDriver(mod);
bind_XmlMDataStd_ExtStringListDriver(mod);
bind_XmlMDataStd_IntegerArrayDriver(mod);
bind_XmlMDataStd_IntegerDriver(mod);
bind_XmlMDataStd_IntegerListDriver(mod);
bind_XmlMDataStd_IntPackedMapDriver(mod);
bind_XmlMDataStd_NamedDataDriver(mod);
bind_XmlMDataStd_NameDriver(mod);
bind_XmlMDataStd_NoteBookDriver(mod);
bind_XmlMDataStd_RealArrayDriver(mod);
bind_XmlMDataStd_RealDriver(mod);
bind_XmlMDataStd_RealListDriver(mod);
bind_XmlMDataStd_ReferenceArrayDriver(mod);
bind_XmlMDataStd_ReferenceListDriver(mod);
bind_XmlMDataStd_RelationDriver(mod);
bind_XmlMDataStd_TickDriver(mod);
bind_XmlMDataStd_TreeNodeDriver(mod);
bind_XmlMDataStd_UAttributeDriver(mod);
bind_XmlMDataStd_VariableDriver(mod);

}
