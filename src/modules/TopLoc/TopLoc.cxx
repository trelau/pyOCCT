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

void bind_HashCode(py::module &);
void bind_ShallowDump(py::module &);
void bind_TopLoc_SListOfItemLocation(py::module &);
void bind_TopLoc_Location(py::module &);
void bind_TopLoc_ItemLocation(py::module &);
void bind_TopLoc_MapLocationHasher(py::module &);
void bind_TopLoc_IndexedMapOfLocation(py::module &);
void bind_TopLoc_Datum3D(py::module &);
void bind_TopLoc_MapOfLocation(py::module &);
void bind_TopLoc_MapIteratorOfMapOfLocation(py::module &);
void bind_TopLoc_SListNodeOfItemLocation(py::module &);

PYBIND11_MODULE(TopLoc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");

bind_HashCode(mod);
bind_ShallowDump(mod);
bind_TopLoc_SListOfItemLocation(mod);
bind_TopLoc_Location(mod);
bind_TopLoc_ItemLocation(mod);
bind_TopLoc_MapLocationHasher(mod);
bind_TopLoc_IndexedMapOfLocation(mod);
bind_TopLoc_Datum3D(mod);
bind_TopLoc_MapOfLocation(mod);
bind_TopLoc_MapIteratorOfMapOfLocation(mod);
bind_TopLoc_SListNodeOfItemLocation(mod);

}
