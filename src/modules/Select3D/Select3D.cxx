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

void bind_Select3D_TypeOfSensitivity(py::module &);
void bind_Select3D_BndBox3d(py::module &);
void bind_Select3D_Vec3(py::module &);
void bind_Select3D_BVHBuilder3d(py::module &);
void bind_Select3D_SensitiveEntity(py::module &);
void bind_Select3D_SensitiveSet(py::module &);
void bind_Select3D_SensitiveFace(py::module &);
void bind_Select3D_SensitiveSegment(py::module &);
void bind_Select3D_BVHIndexBuffer(py::module &);
void bind_Select3D_EntitySequence(py::module &);
void bind_Select3D_EntitySequenceIter(py::module &);
void bind_Select3D_IndexedMapOfEntity(py::module &);
void bind_Select3D_Pnt(py::module &);
void bind_Select3D_PointData(py::module &);
void bind_Select3D_SensitivePoly(py::module &);
void bind_Select3D_VectorOfHPoly(py::module &);
void bind_Select3D_InteriorSensitivePointSet(py::module &);
void bind_Select3D_SensitiveBox(py::module &);
void bind_Select3D_SensitiveCircle(py::module &);
void bind_Select3D_SensitiveCurve(py::module &);
void bind_Select3D_SensitiveGroup(py::module &);
void bind_Select3D_SensitivePoint(py::module &);
void bind_Select3D_SensitivePrimitiveArray(py::module &);
void bind_Select3D_SensitiveTriangle(py::module &);
void bind_Select3D_SensitiveTriangulation(py::module &);
void bind_Select3D_SensitiveWire(py::module &);

PYBIND11_MODULE(Select3D, mod) {

py::module::import("OCCT.BVH");
py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.SelectBasics");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Poly");

bind_Select3D_TypeOfSensitivity(mod);
bind_Select3D_BndBox3d(mod);
bind_Select3D_Vec3(mod);
bind_Select3D_BVHBuilder3d(mod);
bind_Select3D_SensitiveEntity(mod);
bind_Select3D_SensitiveSet(mod);
bind_Select3D_SensitiveFace(mod);
bind_Select3D_SensitiveSegment(mod);
bind_Select3D_BVHIndexBuffer(mod);
bind_Select3D_EntitySequence(mod);
bind_Select3D_EntitySequenceIter(mod);
bind_Select3D_IndexedMapOfEntity(mod);
bind_Select3D_Pnt(mod);
bind_Select3D_PointData(mod);
bind_Select3D_SensitivePoly(mod);
bind_Select3D_VectorOfHPoly(mod);
bind_Select3D_InteriorSensitivePointSet(mod);
bind_Select3D_SensitiveBox(mod);
bind_Select3D_SensitiveCircle(mod);
bind_Select3D_SensitiveCurve(mod);
bind_Select3D_SensitiveGroup(mod);
bind_Select3D_SensitivePoint(mod);
bind_Select3D_SensitivePrimitiveArray(mod);
bind_Select3D_SensitiveTriangle(mod);
bind_Select3D_SensitiveTriangulation(mod);
bind_Select3D_SensitiveWire(mod);

}
