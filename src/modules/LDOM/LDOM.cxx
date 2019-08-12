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

void bind_LDOM_MemManager(py::module &);
void bind_LDOM_Node(py::module &);
void bind_LDOM_Attr(py::module &);
void bind_LDOM_NodeList(py::module &);
void bind_LDOM_Element(py::module &);
void bind_LDOM_CharacterData(py::module &);
void bind_LDOM_Text(py::module &);
void bind_LDOM_CDATASection(py::module &);
void bind_LDOM_Comment(py::module &);
void bind_LDOM_Document(py::module &);
void bind_LDOM_SBuffer(py::module &);
void bind_LDOM_OSStream(py::module &);
void bind_LDOM_BasicNode(py::module &);
void bind_LDOM_BasicAttribute(py::module &);
void bind_LDOM_BasicElement(py::module &);
void bind_LDOM_BasicText(py::module &);
void bind_LDOM_CharReference(py::module &);
void bind_LDOM_DocumentType(py::module &);
void bind_LDOM_LDOMImplementation(py::module &);
void bind_LDOM_XmlReader(py::module &);
void bind_LDOM_XmlWriter(py::module &);

PYBIND11_MODULE(LDOM, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.LDOMBasicString");
py::module::import("OCCT.LDOMParser");
py::module::import("OCCT.LDOMString");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");

bind_LDOM_MemManager(mod);
bind_LDOM_Node(mod);
bind_LDOM_Attr(mod);
bind_LDOM_NodeList(mod);
bind_LDOM_Element(mod);
bind_LDOM_CharacterData(mod);
bind_LDOM_Text(mod);
bind_LDOM_CDATASection(mod);
bind_LDOM_Comment(mod);
bind_LDOM_Document(mod);
bind_LDOM_SBuffer(mod);
bind_LDOM_OSStream(mod);
bind_LDOM_BasicNode(mod);
bind_LDOM_BasicAttribute(mod);
bind_LDOM_BasicElement(mod);
bind_LDOM_BasicText(mod);
bind_LDOM_CharReference(mod);
bind_LDOM_DocumentType(mod);
bind_LDOM_LDOMImplementation(mod);
bind_LDOM_XmlReader(mod);
bind_LDOM_XmlWriter(mod);

}
