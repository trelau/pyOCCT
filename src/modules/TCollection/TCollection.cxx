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

void bind_TCollection_Side(py::module &);
void bind_HashCode(py::module &);
void bind_IsEqual(py::module &);
void bind_TCollection_AsciiString(py::module &);
void bind_TCollection_ExtendedString(py::module &);
void bind_TCollection_HAsciiString(py::module &);
void bind_TCollection_HExtendedString(py::module &);
void bind_TCollection_BasicMap(py::module &);
void bind_TCollection_BasicMapIterator(py::module &);
void bind_TCollection(py::module &);
void bind_TCollection_BaseSequence(py::module &);
void bind_TCollection_MapNodePtr(py::module &);
void bind_TCollection_MapNode(py::module &);
void bind_TCollection_SeqNodePtr(py::module &);
void bind_TCollection_SeqNode(py::module &);

PYBIND11_MODULE(TCollection, mod) {

py::module::import("OCCT.Standard");

bind_TCollection_Side(mod);
bind_HashCode(mod);
bind_IsEqual(mod);
bind_TCollection_AsciiString(mod);
bind_TCollection_ExtendedString(mod);
bind_TCollection_HAsciiString(mod);
bind_TCollection_HExtendedString(mod);
bind_TCollection_BasicMap(mod);
bind_TCollection_BasicMapIterator(mod);
bind_TCollection(mod);
bind_TCollection_BaseSequence(mod);
bind_TCollection_MapNodePtr(mod);
bind_TCollection_MapNode(mod);
bind_TCollection_SeqNodePtr(mod);
bind_TCollection_SeqNode(mod);

}
