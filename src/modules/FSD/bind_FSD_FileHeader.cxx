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
#include <Standard_TypeDef.hxx>
#include <FSD_FileHeader.hxx>

void bind_FSD_FileHeader(py::module &mod){

py::class_<FSD_FileHeader> cls_FSD_FileHeader(mod, "FSD_FileHeader", "None");

// Constructors

// Fields
cls_FSD_FileHeader.def_readwrite("testindian", &FSD_FileHeader::testindian, "None");
cls_FSD_FileHeader.def_readwrite("binfo", &FSD_FileHeader::binfo, "None");
cls_FSD_FileHeader.def_readwrite("einfo", &FSD_FileHeader::einfo, "None");
cls_FSD_FileHeader.def_readwrite("bcomment", &FSD_FileHeader::bcomment, "None");
cls_FSD_FileHeader.def_readwrite("ecomment", &FSD_FileHeader::ecomment, "None");
cls_FSD_FileHeader.def_readwrite("btype", &FSD_FileHeader::btype, "None");
cls_FSD_FileHeader.def_readwrite("etype", &FSD_FileHeader::etype, "None");
cls_FSD_FileHeader.def_readwrite("broot", &FSD_FileHeader::broot, "None");
cls_FSD_FileHeader.def_readwrite("eroot", &FSD_FileHeader::eroot, "None");
cls_FSD_FileHeader.def_readwrite("bref", &FSD_FileHeader::bref, "None");
cls_FSD_FileHeader.def_readwrite("eref", &FSD_FileHeader::eref, "None");
cls_FSD_FileHeader.def_readwrite("bdata", &FSD_FileHeader::bdata, "None");
cls_FSD_FileHeader.def_readwrite("edata", &FSD_FileHeader::edata, "None");

// Methods

// Enums

}