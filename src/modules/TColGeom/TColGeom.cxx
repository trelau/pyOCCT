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

void bind_TColGeom_Array1OfSurface(py::module &);
void bind_TColGeom_HArray1OfSurface(py::module &);
void bind_TColGeom_SequenceOfCurve(py::module &);
void bind_TColGeom_Array1OfBSplineCurve(py::module &);
void bind_TColGeom_HArray1OfBSplineCurve(py::module &);
void bind_TColGeom_Array1OfBezierCurve(py::module &);
void bind_TColGeom_Array2OfBezierSurface(py::module &);
void bind_TColGeom_SequenceOfBoundedCurve(py::module &);
void bind_TColGeom_HSequenceOfBoundedCurve(py::module &);
void bind_TColGeom_Array2OfSurface(py::module &);
void bind_TColGeom_HArray2OfSurface(py::module &);
void bind_TColGeom_HSequenceOfCurve(py::module &);
void bind_TColGeom_Array1OfCurve(py::module &);
void bind_TColGeom_HArray1OfCurve(py::module &);
void bind_TColGeom_HArray1OfBezierCurve(py::module &);
void bind_TColGeom_SequenceOfSurface(py::module &);

PYBIND11_MODULE(TColGeom, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");

bind_TColGeom_Array1OfSurface(mod);
bind_TColGeom_HArray1OfSurface(mod);
bind_TColGeom_SequenceOfCurve(mod);
bind_TColGeom_Array1OfBSplineCurve(mod);
bind_TColGeom_HArray1OfBSplineCurve(mod);
bind_TColGeom_Array1OfBezierCurve(mod);
bind_TColGeom_Array2OfBezierSurface(mod);
bind_TColGeom_SequenceOfBoundedCurve(mod);
bind_TColGeom_HSequenceOfBoundedCurve(mod);
bind_TColGeom_Array2OfSurface(mod);
bind_TColGeom_HArray2OfSurface(mod);
bind_TColGeom_HSequenceOfCurve(mod);
bind_TColGeom_Array1OfCurve(mod);
bind_TColGeom_HArray1OfCurve(mod);
bind_TColGeom_HArray1OfBezierCurve(mod);
bind_TColGeom_SequenceOfSurface(mod);

}
