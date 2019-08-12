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

void bind_TColgp_Array1OfPnt2d(py::module &);
void bind_TColgp_HArray1OfPnt2d(py::module &);
void bind_TColgp_Array1OfPnt(py::module &);
void bind_TColgp_Array2OfPnt(py::module &);
void bind_TColgp_HArray2OfPnt(py::module &);
void bind_TColgp_Array2OfPnt2d(py::module &);
void bind_TColgp_HArray2OfPnt2d(py::module &);
void bind_TColgp_HArray1OfPnt(py::module &);
void bind_TColgp_SequenceOfPnt(py::module &);
void bind_TColgp_HSequenceOfPnt(py::module &);
void bind_TColgp_Array1OfDir(py::module &);
void bind_TColgp_HArray1OfDir(py::module &);
void bind_TColgp_Array1OfVec(py::module &);
void bind_TColgp_HArray1OfVec(py::module &);
void bind_TColgp_Array1OfVec2d(py::module &);
void bind_TColgp_HArray1OfVec2d(py::module &);
void bind_TColgp_SequenceOfArray1OfPnt2d(py::module &);
void bind_TColgp_Array2OfXYZ(py::module &);
void bind_TColgp_HArray2OfXYZ(py::module &);
void bind_TColgp_Array1OfXYZ(py::module &);
void bind_TColgp_SequenceOfXY(py::module &);
void bind_TColgp_SequenceOfXYZ(py::module &);
void bind_TColgp_SequenceOfPnt2d(py::module &);
void bind_TColgp_SequenceOfAx1(py::module &);
void bind_TColgp_HSequenceOfXY(py::module &);
void bind_TColgp_Array2OfVec(py::module &);
void bind_TColgp_Array1OfXY(py::module &);
void bind_TColgp_Array1OfCirc2d(py::module &);
void bind_TColgp_Array1OfLin2d(py::module &);
void bind_TColgp_SequenceOfVec(py::module &);
void bind_TColgp_HArray1OfXYZ(py::module &);
void bind_TColgp_HArray1OfXY(py::module &);
void bind_TColgp_HSequenceOfXYZ(py::module &);
void bind_TColgp_Array1OfDir2d(py::module &);
void bind_TColgp_HArray1OfDir2d(py::module &);
void bind_TColgp_HArray1OfLin2d(py::module &);
void bind_TColgp_HArray1OfCirc2d(py::module &);
void bind_TColgp_Array2OfDir(py::module &);
void bind_TColgp_HArray2OfDir(py::module &);
void bind_TColgp_HArray2OfVec(py::module &);
void bind_TColgp_Array2OfXY(py::module &);
void bind_TColgp_HArray2OfXY(py::module &);
void bind_TColgp_Array2OfDir2d(py::module &);
void bind_TColgp_HArray2OfDir2d(py::module &);
void bind_TColgp_Array2OfVec2d(py::module &);
void bind_TColgp_HArray2OfVec2d(py::module &);
void bind_TColgp_Array2OfLin2d(py::module &);
void bind_TColgp_HArray2OfLin2d(py::module &);
void bind_TColgp_Array2OfCirc2d(py::module &);
void bind_TColgp_HArray2OfCirc2d(py::module &);
void bind_TColgp_SequenceOfDir(py::module &);
void bind_TColgp_HSequenceOfDir(py::module &);
void bind_TColgp_HSequenceOfVec(py::module &);
void bind_TColgp_SequenceOfDir2d(py::module &);
void bind_TColgp_HSequenceOfDir2d(py::module &);
void bind_TColgp_HSequenceOfPnt2d(py::module &);
void bind_TColgp_SequenceOfVec2d(py::module &);
void bind_TColgp_HSequenceOfVec2d(py::module &);

PYBIND11_MODULE(TColgp, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");

bind_TColgp_Array1OfPnt2d(mod);
bind_TColgp_HArray1OfPnt2d(mod);
bind_TColgp_Array1OfPnt(mod);
bind_TColgp_Array2OfPnt(mod);
bind_TColgp_HArray2OfPnt(mod);
bind_TColgp_Array2OfPnt2d(mod);
bind_TColgp_HArray2OfPnt2d(mod);
bind_TColgp_HArray1OfPnt(mod);
bind_TColgp_SequenceOfPnt(mod);
bind_TColgp_HSequenceOfPnt(mod);
bind_TColgp_Array1OfDir(mod);
bind_TColgp_HArray1OfDir(mod);
bind_TColgp_Array1OfVec(mod);
bind_TColgp_HArray1OfVec(mod);
bind_TColgp_Array1OfVec2d(mod);
bind_TColgp_HArray1OfVec2d(mod);
bind_TColgp_SequenceOfArray1OfPnt2d(mod);
bind_TColgp_Array2OfXYZ(mod);
bind_TColgp_HArray2OfXYZ(mod);
bind_TColgp_Array1OfXYZ(mod);
bind_TColgp_SequenceOfXY(mod);
bind_TColgp_SequenceOfXYZ(mod);
bind_TColgp_SequenceOfPnt2d(mod);
bind_TColgp_SequenceOfAx1(mod);
bind_TColgp_HSequenceOfXY(mod);
bind_TColgp_Array2OfVec(mod);
bind_TColgp_Array1OfXY(mod);
bind_TColgp_Array1OfCirc2d(mod);
bind_TColgp_Array1OfLin2d(mod);
bind_TColgp_SequenceOfVec(mod);
bind_TColgp_HArray1OfXYZ(mod);
bind_TColgp_HArray1OfXY(mod);
bind_TColgp_HSequenceOfXYZ(mod);
bind_TColgp_Array1OfDir2d(mod);
bind_TColgp_HArray1OfDir2d(mod);
bind_TColgp_HArray1OfLin2d(mod);
bind_TColgp_HArray1OfCirc2d(mod);
bind_TColgp_Array2OfDir(mod);
bind_TColgp_HArray2OfDir(mod);
bind_TColgp_HArray2OfVec(mod);
bind_TColgp_Array2OfXY(mod);
bind_TColgp_HArray2OfXY(mod);
bind_TColgp_Array2OfDir2d(mod);
bind_TColgp_HArray2OfDir2d(mod);
bind_TColgp_Array2OfVec2d(mod);
bind_TColgp_HArray2OfVec2d(mod);
bind_TColgp_Array2OfLin2d(mod);
bind_TColgp_HArray2OfLin2d(mod);
bind_TColgp_Array2OfCirc2d(mod);
bind_TColgp_HArray2OfCirc2d(mod);
bind_TColgp_SequenceOfDir(mod);
bind_TColgp_HSequenceOfDir(mod);
bind_TColgp_HSequenceOfVec(mod);
bind_TColgp_SequenceOfDir2d(mod);
bind_TColgp_HSequenceOfDir2d(mod);
bind_TColgp_HSequenceOfPnt2d(mod);
bind_TColgp_SequenceOfVec2d(mod);
bind_TColgp_HSequenceOfVec2d(mod);

}
