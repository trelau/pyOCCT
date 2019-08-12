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

void bind_MAT2d_DataMapOfIntegerBisec(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfIntegerBisec(py::module &);
void bind_MAT2d_DataMapOfIntegerPnt2d(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfIntegerPnt2d(py::module &);
void bind_MAT2d_DataMapOfIntegerVec2d(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfIntegerVec2d(py::module &);
void bind_MAT2d_Tool2d(py::module &);
void bind_MAT2d_BiInt(py::module &);
void bind_MAT2d_MapBiIntHasher(py::module &);
void bind_MAT2d_DataMapOfBiIntInteger(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfBiIntInteger(py::module &);
void bind_MAT2d_SequenceOfSequenceOfCurve(py::module &);
void bind_MAT2d_Connexion(py::module &);
void bind_MAT2d_Array2OfConnexion(py::module &);
void bind_MAT2d_DataMapOfIntegerConnexion(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfIntegerConnexion(py::module &);
void bind_MAT2d_DataMapOfBiIntSequenceOfInteger(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfBiIntSequenceOfInteger(py::module &);
void bind_MAT2d_SequenceOfSequenceOfGeometry(py::module &);
void bind_MAT2d_SequenceOfConnexion(py::module &);
void bind_MAT2d_Circuit(py::module &);
void bind_MAT2d_CutCurve(py::module &);
void bind_MAT2d_DataMapOfIntegerSequenceOfConnexion(py::module &);
void bind_MAT2d_DataMapIteratorOfDataMapOfIntegerSequenceOfConnexion(py::module &);
void bind_MAT2d_Mat2d(py::module &);
void bind_MAT2d_MiniPath(py::module &);

PYBIND11_MODULE(MAT2d, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bisector");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.MAT");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColGeom2d");

bind_MAT2d_DataMapOfIntegerBisec(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfIntegerBisec(mod);
bind_MAT2d_DataMapOfIntegerPnt2d(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfIntegerPnt2d(mod);
bind_MAT2d_DataMapOfIntegerVec2d(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfIntegerVec2d(mod);
bind_MAT2d_Tool2d(mod);
bind_MAT2d_BiInt(mod);
bind_MAT2d_MapBiIntHasher(mod);
bind_MAT2d_DataMapOfBiIntInteger(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfBiIntInteger(mod);
bind_MAT2d_SequenceOfSequenceOfCurve(mod);
bind_MAT2d_Connexion(mod);
bind_MAT2d_Array2OfConnexion(mod);
bind_MAT2d_DataMapOfIntegerConnexion(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfIntegerConnexion(mod);
bind_MAT2d_DataMapOfBiIntSequenceOfInteger(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfBiIntSequenceOfInteger(mod);
bind_MAT2d_SequenceOfSequenceOfGeometry(mod);
bind_MAT2d_SequenceOfConnexion(mod);
bind_MAT2d_Circuit(mod);
bind_MAT2d_CutCurve(mod);
bind_MAT2d_DataMapOfIntegerSequenceOfConnexion(mod);
bind_MAT2d_DataMapIteratorOfDataMapOfIntegerSequenceOfConnexion(mod);
bind_MAT2d_Mat2d(mod);
bind_MAT2d_MiniPath(mod);

}
