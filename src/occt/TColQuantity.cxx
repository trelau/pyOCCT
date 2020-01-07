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
#include <NCollection_Array1.hxx>
#include <Quantity_Length.hxx>
#include <TColQuantity_Array1OfLength.hxx>
#include <NCollection_Array2.hxx>
#include <TColQuantity_Array2OfLength.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColQuantity_HArray1OfLength.hxx>
#include <Standard_Type.hxx>
#include <TColQuantity_HArray2OfLength.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_Define_HArray2.hxx>

PYBIND11_MODULE(TColQuantity, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Standard");

// TYPEDEF: TCOLQUANTITY_ARRAY1OFLENGTH
bind_NCollection_Array1<double>(mod, "TColQuantity_Array1OfLength", py::module_local());

// TYPEDEF: TCOLQUANTITY_ARRAY2OFLENGTH
bind_NCollection_Array2<double>(mod, "TColQuantity_Array2OfLength", py::module_local());

// CLASS: TCOLQUANTITY_HARRAY1OFLENGTH
bind_Define_HArray1<TColQuantity_HArray1OfLength, TColQuantity_Array1OfLength>(mod, "TColQuantity_HArray1OfLength");

// CLASS: TCOLQUANTITY_HARRAY2OFLENGTH
bind_Define_HArray2<TColQuantity_HArray2OfLength, TColQuantity_Array2OfLength>(mod, "TColQuantity_HArray2OfLength");


}
