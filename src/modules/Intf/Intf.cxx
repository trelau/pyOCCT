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

void bind_Intf_PIType(py::module &);
void bind_Intf_Polygon2d(py::module &);
void bind_Intf_SectionPoint(py::module &);
void bind_Intf_SeqOfSectionPoint(py::module &);
void bind_Intf_SectionLine(py::module &);
void bind_Intf_SeqOfSectionLine(py::module &);
void bind_Intf_TangentZone(py::module &);
void bind_Intf_SeqOfTangentZone(py::module &);
void bind_Intf_Interference(py::module &);
void bind_Intf_Array1OfLin(py::module &);
void bind_Intf(py::module &);
void bind_Intf_InterferencePolygon2d(py::module &);
void bind_Intf_Tool(py::module &);

PYBIND11_MODULE(Intf, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");

bind_Intf_PIType(mod);
bind_Intf_Polygon2d(mod);
bind_Intf_SectionPoint(mod);
bind_Intf_SeqOfSectionPoint(mod);
bind_Intf_SectionLine(mod);
bind_Intf_SeqOfSectionLine(mod);
bind_Intf_TangentZone(mod);
bind_Intf_SeqOfTangentZone(mod);
bind_Intf_Interference(mod);
bind_Intf_Array1OfLin(mod);
bind_Intf(mod);
bind_Intf_InterferencePolygon2d(mod);
bind_Intf_Tool(mod);

}
