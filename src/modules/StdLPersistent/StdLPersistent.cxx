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

void bind_StdLPersistent_HArray1OfPersistent(py::module &);
void bind_StdLPersistent_HArray1(py::module &);
void bind_StdLPersistent_HArray2OfPersistent(py::module &);
void bind_StdLPersistent_HArray2(py::module &);
void bind_StdLPersistent(py::module &);
void bind_StdLPersistent_Collection(py::module &);
void bind_StdLPersistent_Data(py::module &);
void bind_StdLPersistent_HString(py::module &);
void bind_StdLPersistent_Dependency(py::module &);
void bind_StdLPersistent_Document(py::module &);
void bind_StdLPersistent_Function(py::module &);
void bind_StdLPersistent_NamedData(py::module &);
void bind_StdLPersistent_Real(py::module &);
void bind_StdLPersistent_TreeNode(py::module &);
void bind_StdLPersistent_Value(py::module &);
void bind_StdLPersistent_Variable(py::module &);
void bind_StdLPersistent_Void(py::module &);
void bind_StdLPersistent_XLink(py::module &);

PYBIND11_MODULE(StdLPersistent, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.TFunction");

bind_StdLPersistent_HArray1OfPersistent(mod);
bind_StdLPersistent_HArray1(mod);
bind_StdLPersistent_HArray2OfPersistent(mod);
bind_StdLPersistent_HArray2(mod);
bind_StdLPersistent(mod);
bind_StdLPersistent_Collection(mod);
bind_StdLPersistent_Data(mod);
bind_StdLPersistent_HString(mod);
bind_StdLPersistent_Dependency(mod);
bind_StdLPersistent_Document(mod);
bind_StdLPersistent_Function(mod);
bind_StdLPersistent_NamedData(mod);
bind_StdLPersistent_Real(mod);
bind_StdLPersistent_TreeNode(mod);
bind_StdLPersistent_Value(mod);
bind_StdLPersistent_Variable(mod);
bind_StdLPersistent_Void(mod);
bind_StdLPersistent_XLink(mod);

}
