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
void bind_IsEqual(py::module &);
void bind_Poly_Triangle(py::module &);
void bind_Poly_Array1OfTriangle(py::module &);
void bind_Poly_Triangulation(py::module &);
void bind_Poly_Polygon3D(py::module &);
void bind_Poly_PolygonOnTriangulation(py::module &);
void bind_Poly_Polygon2D(py::module &);
void bind_Poly_ListOfTriangulation(py::module &);
void bind_Poly(py::module &);
void bind_Poly_CoherentLink(py::module &);
void bind_Poly_CoherentTriPtr(py::module &);
void bind_Poly_CoherentNode(py::module &);
void bind_Poly_CoherentTriangle(py::module &);
void bind_Poly_BaseIteratorOfCoherentTriangle(py::module &);
void bind_Poly_BaseIteratorOfCoherentNode(py::module &);
void bind_Poly_BaseIteratorOfCoherentLink(py::module &);
void bind_Poly_CoherentTriangulation(py::module &);
void bind_Poly_Connect(py::module &);
void bind_Poly_HArray1OfTriangle(py::module &);
void bind_Poly_MakeLoops(py::module &);
void bind_Poly_MakeLoops3D(py::module &);
void bind_Poly_MakeLoops2D(py::module &);

PYBIND11_MODULE(Poly, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.TShort");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Precision");

bind_HashCode(mod);
bind_IsEqual(mod);
bind_Poly_Triangle(mod);
bind_Poly_Array1OfTriangle(mod);
bind_Poly_Triangulation(mod);
bind_Poly_Polygon3D(mod);
bind_Poly_PolygonOnTriangulation(mod);
bind_Poly_Polygon2D(mod);
bind_Poly_ListOfTriangulation(mod);
bind_Poly(mod);
bind_Poly_CoherentLink(mod);
bind_Poly_CoherentTriPtr(mod);
bind_Poly_CoherentNode(mod);
bind_Poly_CoherentTriangle(mod);
bind_Poly_BaseIteratorOfCoherentTriangle(mod);
bind_Poly_BaseIteratorOfCoherentNode(mod);
bind_Poly_BaseIteratorOfCoherentLink(mod);
bind_Poly_CoherentTriangulation(mod);
bind_Poly_Connect(mod);
bind_Poly_HArray1OfTriangle(mod);
bind_Poly_MakeLoops(mod);
bind_Poly_MakeLoops3D(mod);
bind_Poly_MakeLoops2D(mod);

}
