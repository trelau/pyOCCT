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

void bind_IntPolyh_Edge(py::module &);
void bind_IntPolyh_ArrayOfEdges(py::module &);
void bind_IntPolyh_PointNormal(py::module &);
void bind_IntPolyh_ArrayOfPointNormal(py::module &);
void bind_IntPolyh_Point(py::module &);
void bind_IntPolyh_ArrayOfPoints(py::module &);
void bind_IntPolyh_StartPoint(py::module &);
void bind_IntPolyh_SeqOfStartPoints(py::module &);
void bind_IntPolyh_SectionLine(py::module &);
void bind_IntPolyh_ArrayOfSectionLines(py::module &);
void bind_IntPolyh_ArrayOfTangentZones(py::module &);
void bind_IntPolyh_ArrayOfTriangles(py::module &);
void bind_IntPolyh_Couple(py::module &);
void bind_IntPolyh_CoupleMapHasher(py::module &);
void bind_IntPolyh_ListOfCouples(py::module &);
void bind_IntPolyh_ListIteratorOfListOfCouples(py::module &);
void bind_IntPolyh_PMaillageAffinage(py::module &);
void bind_IntPolyh_Intersection(py::module &);
void bind_IntPolyh_MaillageAffinage(py::module &);
void bind_IntPolyh_Tools(py::module &);
void bind_IntPolyh_Triangle(py::module &);

PYBIND11_MODULE(IntPolyh, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Bnd");

bind_IntPolyh_Edge(mod);
bind_IntPolyh_ArrayOfEdges(mod);
bind_IntPolyh_PointNormal(mod);
bind_IntPolyh_ArrayOfPointNormal(mod);
bind_IntPolyh_Point(mod);
bind_IntPolyh_ArrayOfPoints(mod);
bind_IntPolyh_StartPoint(mod);
bind_IntPolyh_SeqOfStartPoints(mod);
bind_IntPolyh_SectionLine(mod);
bind_IntPolyh_ArrayOfSectionLines(mod);
bind_IntPolyh_ArrayOfTangentZones(mod);
bind_IntPolyh_ArrayOfTriangles(mod);
bind_IntPolyh_Couple(mod);
bind_IntPolyh_CoupleMapHasher(mod);
bind_IntPolyh_ListOfCouples(mod);
bind_IntPolyh_ListIteratorOfListOfCouples(mod);
bind_IntPolyh_PMaillageAffinage(mod);
bind_IntPolyh_Intersection(mod);
bind_IntPolyh_MaillageAffinage(mod);
bind_IntPolyh_Tools(mod);
bind_IntPolyh_Triangle(mod);

}
