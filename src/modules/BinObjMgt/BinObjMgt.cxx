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

void bind_BinObjMgt_PChar(py::module &);
void bind_BinObjMgt_PByte(py::module &);
void bind_BinObjMgt_PExtChar(py::module &);
void bind_BinObjMgt_PInteger(py::module &);
void bind_BinObjMgt_PReal(py::module &);
void bind_BinObjMgt_PShortReal(py::module &);
void bind_BinObjMgt_Persistent(py::module &);
void bind_BinObjMgt_RRelocationTable(py::module &);
void bind_BinObjMgt_SRelocationTable(py::module &);

PYBIND11_MODULE(BinObjMgt, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Storage");

bind_BinObjMgt_PChar(mod);
bind_BinObjMgt_PByte(mod);
bind_BinObjMgt_PExtChar(mod);
bind_BinObjMgt_PInteger(mod);
bind_BinObjMgt_PReal(mod);
bind_BinObjMgt_PShortReal(mod);
bind_BinObjMgt_Persistent(mod);
bind_BinObjMgt_RRelocationTable(mod);
bind_BinObjMgt_SRelocationTable(mod);

}
